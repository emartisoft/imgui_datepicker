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

#pragma once

#ifdef USE_TURKISH
// Türkçe dil değişkenleri
    #define LANG_YIL "Yıl"
    #define LANG_AY "Ay"
    #define LANG_GUN "Gün"
    #define LANG_BUGUN "Bugün"
    #define LANG_TAMAM "Tamam"
    #define LANG_PAZAR "Pazar"
    #define LANG_PAZARTESI "Pazartesi"
    #define LANG_SALI "Salı"
    #define LANG_CARSAMBA "Çarşamba"
    #define LANG_PERSEMBE "Perşembe"
    #define LANG_CUMA "Cuma"
    #define LANG_CUMARTESI "Cumartesi"
    #define LANG_OCAK "Ocak"
    #define LANG_SUBAT "Şubat"
    #define LANG_MART "Mart"
    #define LANG_NISAN "Nisan"
    #define LANG_MAYIS "Mayıs"
    #define LANG_HAZIRAN "Haziran"
    #define LANG_TEMMUZ "Temmuz"
    #define LANG_AGUSTOS "Ağustos"
    #define LANG_EYLUL "Eylül"
    #define LANG_EKIM "Ekim"
    #define LANG_KASIM "Kasım"
    #define LANG_ARALIK "Aralık"
#elif defined(USE_GERMAN)
// Almanca dil değişkenleri
    #define LANG_YIL "Jahr"
    #define LANG_AY "Monat"
    #define LANG_GUN "Tag"
    #define LANG_BUGUN "Heute"
    #define LANG_TAMAM "OK"
    #define LANG_PAZAR "Sonntag"
    #define LANG_PAZARTESI "Montag"
    #define LANG_SALI "Dienstag"
    #define LANG_CARSAMBA "Mittwoch"
    #define LANG_PERSEMBE "Donnerstag"
    #define LANG_CUMA "Freitag"
    #define LANG_CUMARTESI "Samstag"
    #define LANG_OCAK "Januar"
    #define LANG_SUBAT "Februar"
    #define LANG_MART "März"
    #define LANG_NISAN "April"
    #define LANG_MAYIS "Mai"
    #define LANG_HAZIRAN "Juni"
    #define LANG_TEMMUZ "Juli"
    #define LANG_AGUSTOS "August"
    #define LANG_EYLUL "September"
    #define LANG_EKIM "Oktober"
    #define LANG_KASIM "November"
    #define LANG_ARALIK "Dezember"
#else
// İngilizce dil değişkenleri (varsayılan)
#define LANG_YIL "Year"
#define LANG_AY "Month"
#define LANG_GUN "Day"
#define LANG_BUGUN "Today"
#define LANG_TAMAM "OK"
#define LANG_PAZAR "Sunday"
#define LANG_PAZARTESI "Monday"
#define LANG_SALI "Tuesday"
#define LANG_CARSAMBA "Wednesday"
#define LANG_PERSEMBE "Thursday"
#define LANG_CUMA "Friday"
#define LANG_CUMARTESI "Saturday"
#define LANG_OCAK "January"
#define LANG_SUBAT "February"
#define LANG_MART "March"
#define LANG_NISAN "April"
#define LANG_MAYIS "May"
#define LANG_HAZIRAN "June"
#define LANG_TEMMUZ "July"
#define LANG_AGUSTOS "August"
#define LANG_EYLUL "September"
#define LANG_EKIM "October"
#define LANG_KASIM "November"
#define LANG_ARALIK "December"
#endif
