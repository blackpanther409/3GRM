import socket

#creating a socket object, by AF_INET we are using IPv4 protocol and by SOCK_STREAM we are using TCP
s= socket.socket(socket.AF_INET,socket.SOCK_STREAM)

#binding hostname with port number and enabling listen
s.bind((socket.gethostname(),1200))
s.listen()

#An infinite loop to always try to accept a request from a client
while True:
    client, address = s.accept()                                  #getting client details if found any
    print(f"Connection from {address} has been established!!!")   #printing the details
    client.send(bytes("Welcome to the server!!","utf-8"))         #sending a message which is coded into bytes
    client.close()                                                #the connection is closed    
