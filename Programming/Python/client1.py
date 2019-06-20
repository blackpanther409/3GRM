import socket

s= socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((socket.gethostname(),1200))
print(socket.gethostname())

#buffering the message 
full_msg=''
while True:
  msg = s.recv(8)                   #receiving 8 bytes at a time( can take any number of bytes, its optional)
  if len(msg)>0:
    full_msg +=msg.decode("utf-8")  #adding all the bytes
  else:
        break

#printing the full message
print(full_msg)                 
