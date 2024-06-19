# imgui_datepicker
date picker widget for imgui

## usage
```cpp
 //#define USE_TURKISH
 //#define USE_GERMAN
 //default english
 #include <imgui_datepicker.h>
 ...
 static DatePicker datePicker("2024-03-29", 1); // date format yyyy-mm-dd
 datePicker.setHoverColor(ImVec4(136 / 255.0f, 153 / 255.0f, 255 / 255.0f, 1.0f)); // default is red
 datePicker.Show();
 ImGui::Text(datePicker.GetDate().c_str());
```

