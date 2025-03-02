#include <WiFi.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/segoeui5pt7b.h>
#include <Fonts/segoeui6pt7b.h>

#include <NTPClient.h>

#include <Graphics/icons.h>

#include <All_Variables/Const_Variables.h>
#include <All_Variables/Variables.h>

#include <BluetoothA2DPSink.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
BluetoothA2DPSink a2dp_sink;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


void setup() {
  Serial.begin(921600);
  Wire.begin(21, 22); 
  

  display.setFont(&segoeui5pt7b);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED error!");
    while (1);
  }

  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  display.display();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(10);
  }

  timeClient.begin();

  a2dp_sink.set_avrc_metadata_callback(avrc_metadata_callback);
  a2dp_sink.set_avrc_metadata_attribute_mask(ESP_AVRC_MD_ATTR_TITLE | ESP_AVRC_MD_ATTR_ARTIST);
  a2dp_sink.start("YandexMusic_Player");
}


void avrc_metadata_callback(uint8_t attr_id, const uint8_t *attr_data) {
  if (attr_id == ESP_AVRC_MD_ATTR_TITLE) {
    title = "Title: " + String((const char*)attr_data);
  } 
  else if (attr_id == ESP_AVRC_MD_ATTR_ARTIST) {
    artist = "Artist: " + String((const char*)attr_data);
  }

  if (title.length() > 23) {
    title = title.substring(0, 20);
    title.concat("...");
  }
  if (artist.length() > 23) {
    artist = artist.substring(0, 20);
    artist.concat("...");
  }
}


void MainScreen() {
  display.clearDisplay();

  int current_app = CURRENT_COL * CURRENT_ROW;

  if (current_app == 1) {
    display.drawBitmap(0, 0, ActiveIcon1, 128, 64, 1);
    display.display();
  }
  else if (current_app == 2) {
    display.drawBitmap(0, 0, ActiveIcon2, 128, 64, 1);
    display.display();
  }
  else if (current_app == -1) {
    display.drawBitmap(0, 0, ActiveIcon3, 128, 64, 1);
    display.display();
  }
  else if (current_app == -2) {
    display.drawBitmap(0, 0, ActiveIcon4, 128, 64, 1);
    display.display();
  }
}


void Telegram() {
  display.clearDisplay();

  display.setCursor(telegram_heading_x, telegram_heading_y);
  display.println("TELEGRAM");

  if (last_message == "") {
    display.setCursor(25, 35);
    display.println("No messages yet...");
  } else {
    display.setCursor(5, 25);
    display.println("Last message:");

    display.setCursor(5, 40);
    display.println(last_message);
  }

  display.setCursor(X_time, Y_time);
  display.println(curDate);

  display.display();
}


void Music() {
  display.clearDisplay();

  display.setCursor(X_time, Y_time);
  display.println(curDate);

  display.setCursor(50, 10);
  display.print("MUSIC"); 

  display.setCursor(15, 27);
  display.print(title);

  display.setCursor(15, 45);
  display.print(artist);
  

  display.display();
}


void WIFI(int n) {
  display.clearDisplay();
  if (n < 0) {
    CURRENT_PHASE = 0;
    return;
  }

  if (password_wait) {
    display.setFont(&segoeui6pt7b);
    display.clearDisplay();
    display.setCursor(15, 35);
    display.print("Connecting...");
    display.display();

    display.setFont(&segoeui5pt7b);
  } 
  else {
    display.setCursor(available_nets_heading_x, available_nets_heading_y);
    display.print("AVAILABLE NETS:");

    for (int i = 0; i < min(n, 3); i++) {
      display.setCursor(network_name_positions[i][0], network_name_positions[i][1]);
      network_name = WiFi.SSID(i);
      if (network_name.length() > 8) {
        network_name = network_name.substring(0, 5);
        network_name.concat("***"); 
      }
      display.print(network_name);

      display.setCursor(network_connect_positions[i][0], network_connect_positions[i][1]);
      display.print("Connect");

      if (i + 1 == current_net) {
        display.drawRect(rect_positions[i][0], rect_positions[i][1], connect_button_width, connect_button_height, WHITE);
      }
    }

    display.setCursor(X_time, Y_time);
    display.println(curDate);

    display.display();
  } 
}


void Camera() {
  display.clearDisplay();
  if (active_button == 1) {
    display.drawBitmap(0, 0, photo_button_active, 128, 64, 1);
    display.display();
  } 
  else {
    display.drawBitmap(0, 0, video_button_active, 128, 64, 1);
    display.display();
  }
}


void newMessage(String info_sent) {
  int index_split = info_sent.indexOf("@");
  String message = info_sent.substring(0, index_split);
  String user = info_sent.substring(index_split + 1, info_sent.length());

  last_message = message;

  display.clearDisplay();
  display.setCursor(new_message_not_x, new_message_not_y);
  display.print("New Telegram message!");

  display.setCursor(user_new_message_x, user_new_message_y);
  display.print("Sent by: ");
  display.print(user);

  display.setCursor(X_time, Y_time);
  display.println(curDate);

  display.display();
  delay(3000);

  if (last_message.length() > 20) {
    last_message = last_message.substring(0, 17);
    last_message.concat("...");
  }

  total_messages_received += 1;
  messages_received[index_message_array] = last_message;
  index_message_array = (index_message_array + 1) % 1000;
}



void handleGestures(String command) {
  if (command == "telegram" && CURRENT_PHASE == 0) {
    CURRENT_COL = 1;
    CURRENT_ROW = 1;
  }

  else if (command == "camera" && CURRENT_PHASE == 0) {
    CURRENT_COL = 2;
    CURRENT_ROW = 1;
  }

  else if (command == "wifi" && CURRENT_PHASE == 0) {
    CURRENT_COL = 1;
    CURRENT_ROW = -1;
  }

  else if (command == "music" && CURRENT_PHASE == 0) {
    CURRENT_COL = 2;
    CURRENT_ROW = -1;
  }

  else if (command == "back" && CURRENT_PHASE != 0) {
    if (CURRENT_COL * CURRENT_ROW == -1) {
      display.setFont(&segoeui6pt7b);
      display.clearDisplay();
      display.setCursor(connection_notification_x, connection_notification_y);
      display.print("Connecting back...");
      display.display();

      display.setFont(&segoeui5pt7b);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(10);
      }
    }
    CURRENT_PHASE = 0;
  }

  else if (command == "enter") {
    CURRENT_PHASE = CURRENT_COL * CURRENT_ROW;
    if (CURRENT_PHASE == -1) {
      display.setFont(&segoeui6pt7b);
      display.clearDisplay();
      display.setCursor(9, 35);
      display.print("Scanning networks...");
      display.display();

      display.setFont(&segoeui5pt7b);
      nets_available = WiFi.scanNetworks();
    }
  }

  else if (command == "next") {
    if (CURRENT_PHASE == -2) {
      a2dp_sink.next();
    } 
    else if (CURRENT_PHASE == -1) {
      current_net = current_net % 3 + 1;
    } 
    else if (CURRENT_PHASE == 1 && messages_received[(index_message_array + 1) % 1000] != "") {
      index_message_array = (index_message_array + 1) % 1000;
      last_message = messages_received[index_message_array];
    }
    else if (CURRENT_PHASE == 2) {
      active_button %= 2;
      active_button += 1;
    }
  }

  else if (command == "prev") {
    if (CURRENT_PHASE == -2) {
      a2dp_sink.previous();
    } 
    else if (CURRENT_PHASE == 1 && messages_received[(index_message_array + 999) % 1000] != "") {
      index_message_array = (index_message_array + 999) % 1000;
      last_message = messages_received[index_message_array];
    }
  }

  else if (command == "connect" && CURRENT_PHASE == -1) {
    password_wait = true;
    last_time_try_connection = millis();
  }

  else {
    if (password_wait) {
      current_net_password = command;
      password_wait = false;
      connection_proceeding = true;
      last_time_try_connection = millis();

      WiFi.begin(WiFi.SSID(current_net - 1), current_net_password);
    }
    else {
      Serial.println("Received!");
      newMessage(command);
    }
  }
}


void loop() {
  if (WiFi.status() == WL_CONNECTED && connection_proceeding) {
    display.setFont(&segoeui6pt7b);
    display.clearDisplay();
    display.setCursor(5, 35);
    display.print("Connection established!");
    display.display();
    delay(3000);

    display.setFont(&segoeui5pt7b);
    connection_proceeding = false;
  }


  if (CURRENT_PHASE == 0) {
    MainScreen();
  } 
  else if (CURRENT_PHASE == 1) {
    Telegram();
  }
  else if (CURRENT_PHASE == -2) {
    Music();
  }
  else if (CURRENT_PHASE == -1) {
    WIFI(nets_available);
  }
  else if (CURRENT_PHASE == 2) {
    Camera();
  }

  if (Serial.available()) {
    String cmd = Serial.readString();
    handleGestures(cmd);
  }

  if (millis() - curTime > refreshTime) {
    timeClient.update();
    curTime = millis();
    curDate = timeClient.getFormattedTime();
  }

  if (millis() - last_time_try_connection > 15000) {
    if (password_wait) {
      display.setFont(&segoeui6pt7b);
      display.clearDisplay();
      display.setCursor(6, 35);
      display.print("Could not reveive data");
      display.display();
      delay(2500);

      display.setFont(&segoeui5pt7b);
      last_time_try_connection = 0;
      password_wait = false;
    }
    else if (connection_proceeding) {
      display.setFont(&segoeui6pt7b);
      display.clearDisplay();
      display.setCursor(12, 35);
      display.print("Failed to connect!!");
      display.display();
      delay(2500);

      display.setFont(&segoeui5pt7b);
      last_time_try_connection = 0;
      connection_proceeding = false;
    }
  }
}
