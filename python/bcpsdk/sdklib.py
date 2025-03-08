import ctypes
import os
from .structs import *

lib = ctypes.cdll.LoadLibrary(os.path.join(os.path.dirname(__file__), "lib", "bcpsdk.so"))

lib.encodeCommandConnection.argtypes = [ctypes.POINTER(CommandConnection), ctypes.POINTER(MessageBuffer)]
lib.encodeCommandConnection.restype = ctypes.c_int
lib.encodeCommandDisconnect.argtypes = [ctypes.POINTER(CommandDisconnect), ctypes.POINTER(MessageBuffer)]
lib.encodeCommandDisconnect.restype = ctypes.c_int
lib.encodeCommandHardware.argtypes = [ctypes.POINTER(CommandHardware), ctypes.POINTER(MessageBuffer)]
lib.encodeCommandHardware.restype = ctypes.c_int
lib.encodeQuerySoftware.argtypes = [ctypes.POINTER(QuerySoftware), ctypes.POINTER(MessageBuffer)]
lib.encodeQuerySoftware.restype = ctypes.c_int
lib.encode.argtypes = [ctypes.POINTER(BCPMessage), ctypes.POINTER(MessageBuffer)]
lib.encode.restype = ctypes.c_int

# if __name__ == '__main__':
#     msg = BCPMessage()
#     msg.type = 0;
#     msg.data = MessageData()
#     msg.data.CommandConnection = CommandConnection();
#     msg.data.CommandConnection.id = 1;
#     msg.data.CommandConnection.version = b'\x01\x00\x00'
#     l, buf = encode(msg)
#     print(l, buf[:l+1])