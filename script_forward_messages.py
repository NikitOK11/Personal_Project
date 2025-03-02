from telethon import TelegramClient, events
import serial

client = TelegramClient('session_name', 29099872, '721b85af6eddc5c90aa5e3bf9f1cd042')
SERIAL_PORT = 'COM5'
SERIAL_BAUDRATE = 921600

@client.on(events.NewMessage)
async def my_event_handler(event):
    last_message = event.message.message
    user = await event.get_sender()
    info_send = last_message + "@" + user.username

    ser = serial.Serial(port=SERIAL_PORT, baudrate=SERIAL_BAUDRATE, timeout=1)
    ser.write(info_send.encode(encoding='utf-8'))

client.start(password="Nikita110609//")
client.run_until_disconnected()
