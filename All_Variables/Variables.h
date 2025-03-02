unsigned long lastUpdateTime = 0;

int curTime = 0;

//SETUP MODE
String setup_mode = "None";

// MAIN MENU
int CURRENT_PHASE = 0;
int CURRENT_COL = 1;
int CURRENT_ROW = 1;


// TELEGRAM
String last_message = "";
String messages_received [1000];
int index_message_array = 0;
int total_messages_received = 0;
unsigned long bot_lasttime; // last time messages' scan has been done


// MUSIC
String title = "No title detected";
String artist = "No artist detected";


// WI-FI
int nets_available = 0;
int current_net = 1;
int last_time_try_connection = 0;
bool connection_proceeding = false;
bool password_wait = false;

String network_name = "";
String current_net_login = "";
String current_net_password = "";


// CURRENT TIME
int utcOffsetInSeconds = 10800;
String curDate = "";


// CAMERA
unsigned long lastCaptureTime = 0; // Last shooting time
int imageCount = 1;                // File Counter
int videoSecondsDuration = 0;      // Video duration in seconds
bool camera_sign = false;          // Check camera status
bool sd_sign = false;              // Check sd status

int active_button = 1;