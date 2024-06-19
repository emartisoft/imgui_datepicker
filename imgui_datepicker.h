/*
The MIT License (MIT)

Copyright (c) 2024 emarti, Murat Özdemir

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
usage:

 //#define USE_TURKISH
 //#define USE_GERMAN
 //default english
 #include <imgui_datepicker.h>
 ...
 static DatePicker datePicker("2024-03-29", 1); // date format yyyy-mm-dd
 datePicker.setHoverColor(ImVec4(136 / 255.0f, 153 / 255.0f, 255 / 255.0f, 1.0f)); // default is red
 datePicker.Show();
 ImGui::Text(datePicker.GetDate().c_str());
*/

#pragma once

#include <imgui.h>
#include "imgui_datepickerlang.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <array>
#include <functional>

#define COLUMNWIDTH 100

class DatePicker {
public:
    explicit DatePicker(int ID = 0) : uniqueID(ID), hoverColor(ImVec4(1.0f, 0.0f, 0.0f, 1.0f)) {
        today();
        popupName = "Date Picker##" + std::to_string(uniqueID);
    }

    explicit DatePicker(const std::string& fmtdate, int ID = 0) : uniqueID(ID), hoverColor(ImVec4(1.0f, 0.0f, 0.0f, 1.0f)) {
        std::istringstream iss(fmtdate);
        char dash1, dash2;
        iss >> year >> dash1 >> month >> dash2 >> day;
        month--;
        if ((fmtdate.length() != 10) || dash1 != '-' || dash2 != '-' ||
            iss.fail() || year < 1900 || month < 0 || month > 11 || day < 1 || day > 31) {
            today();
        } else {
            formattedDate = fmtdate;
        }
        popupName = "Date Picker##" + std::to_string(uniqueID);
    }

    void Show() {
        std::string buttonLabel = formattedDate + "##" + std::to_string(uniqueID);
        TextWithClickableEvent(buttonLabel.c_str(), [this]() {
            ImGui::OpenPopup(popupName.c_str());
        });

        ImGui::SetNextWindowSizeConstraints(ImVec2(COLUMNWIDTH * 1.5f + 20, 0), ImVec2(COLUMNWIDTH * 1.5f + 20, 300));
        ImGui::SetNextWindowPos(ImGui::GetCursorScreenPos());

        if (ImGui::BeginPopup(popupName.c_str())) {
            const char* months[] = { LANG_OCAK, LANG_SUBAT, LANG_MART, LANG_NISAN, LANG_MAYIS, LANG_HAZIRAN, LANG_TEMMUZ, LANG_AGUSTOS, LANG_EYLUL, LANG_EKIM, LANG_KASIM, LANG_ARALIK };
            static const std::array<int, 12> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

            ImGui::Columns(2, nullptr, true);
            ImGui::SetColumnWidth(0, COLUMNWIDTH * 0.5f);
            ImGui::SetColumnWidth(1, COLUMNWIDTH + 20);

            ImGui::Text(LANG_YIL);
            ImGui::NextColumn();
            ImGui::PushItemWidth(COLUMNWIDTH);
            ImGui::InputInt("##Year", &year);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            ImGui::Text(LANG_AY);
            ImGui::NextColumn();
            ImGui::PushItemWidth(COLUMNWIDTH);
            ImGui::Combo("##Month", &month, months, IM_ARRAYSIZE(months));
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            ImGui::Text(LANG_GUN);
            ImGui::NextColumn();
            ImGui::PushItemWidth(COLUMNWIDTH);
            ImGui::InputInt("##Day", &day);
            ImGui::PopItemWidth();
            ImGui::NextColumn();

            bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            int max_days = days_in_month[month];
            if (month == 1 && is_leap_year) {
                max_days = 29;
            }

            if (day < 1) day = 1;
            if (day > max_days) day = max_days;

            std::tm time_in = { 0, 0, 0, day, month, year - 1900 };
            std::mktime(&time_in);
            const char* days_of_week[] = { LANG_PAZAR, LANG_PAZARTESI, LANG_SALI, LANG_CARSAMBA, LANG_PERSEMBE, LANG_CUMA, LANG_CUMARTESI };
            const char* day_of_week = days_of_week[time_in.tm_wday];

            std::ostringstream oss;
            oss << std::setfill('0') << std::setw(4) << year << "-"
                << std::setw(2) << (month + 1) << "-" // Ayı 1 artırdık çünkü tm_mon 0-11 arası
                << std::setw(2) << day;
            formattedDate = oss.str();

            ImGui::NextColumn();
            ImGui::Text("%s", day_of_week);

            ImGui::Columns(1);

            ImGui::Dummy(ImVec2(0.0f, 8.0f));

            if (ImGui::Button(LANG_BUGUN, ImVec2(COLUMNWIDTH * 0.75f, 0))) {
                today();
            }
            ImGui::SameLine();

            if (ImGui::Button(LANG_TAMAM, ImVec2(COLUMNWIDTH * 0.75f, 0))) {
                ImGui::CloseCurrentPopup();
            }

            ImGui::EndPopup();
        }
    }

    [[nodiscard]] std::string GetDate() const {
        return formattedDate;
    }

    // Set method for hoverColor
    void setHoverColor(const ImVec4& newHoverColor) {
        hoverColor = newHoverColor;
    }

private:
    int year{}, month{}, day{};
    std::string formattedDate;
    int uniqueID;
    std::string popupName;
    ImVec4 hoverColor;

    void today() {
        time_t t = time(nullptr);
        tm* timePtr = localtime(&t);
        year = timePtr->tm_year + 1900;
        month = timePtr->tm_mon;
        day = timePtr->tm_mday;

        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(4) << year << "-"
            << std::setw(2) << (month + 1) << "-" // Ayı 1 artırdık çünkü tm_mon 0-11 arası
            << std::setw(2) << day;
        formattedDate = oss.str();
    }

    void TextWithClickableEvent(const char* text, const std::function<void()>& onClick) {
        ImVec2 textSize = ImGui::CalcTextSize(text);
        ImGui::InvisibleButton(text, textSize);

        if (ImGui::IsItemClicked()) {
            onClick();
        }
        bool isHovered = ImGui::IsItemHovered();

        if (isHovered) {
            ImGui::PushStyleColor(ImGuiCol_Text, hoverColor); // Hover rengi
        }

        // Text'i InvisibleButton üzerine çiz
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() - textSize.x); // InvisibleButton ve Text hizalaması için
        ImGui::TextUnformatted(formattedDate.c_str());

        if (isHovered) {
            ImGui::PopStyleColor();
        }
    }
};
