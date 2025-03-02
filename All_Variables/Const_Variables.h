// WIFI VARIABLES
const char* ssid = "WIFI SSID";
const char* password = "WIFI PASSOWRD";


// TELEGRAM VARIABLES
const unsigned long BOT_MTBS = 1000;

// SCREEN VARIABLES
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_RESET = -1;


const int refreshTime = 500;

const char* conditions [5] = {
  "main_screen",
  "Telegram",
  "Music",
  "Camera",
  "Wi-Fi"
};

const int network_name_positions [3][2] = {
  {10, 23},
  {10, 35},
  {10, 47}
};

const int network_connect_positions [3][2] = {
  {70, 23},
  {70, 35},
  {70, 47}
};

const int rect_positions [3][2] = {
  {67, 16},
  {67, 28},
  {67, 40}
};

const int connect_button_width = 45;
const int connect_button_height = 10;

const int updateInterval = 1000;


//POSITION VARIABLES

// coordinates for displaying time
const int X_time = 80;
const int Y_time = 60;

// cooridnates for new notification from Telegram
const int new_message_not_x = 5;
const int new_message_not_y = 20;

const int user_new_message_x = 5;
const int user_new_message_y = 35;

// coordinates for connection to Wi-Fi after scanning
const int connection_notification_x = 17;
const int connection_notification_y = 35;

// cooridnates for telegram app objects
const int telegram_heading_x = 40;
const int telegram_heading_y = 10;

// cooridnates for wi-fi app objects
const int available_nets_heading_x = 10;
const int available_nets_heading_y = 10;
