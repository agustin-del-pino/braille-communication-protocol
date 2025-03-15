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