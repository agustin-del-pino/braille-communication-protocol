import ctypes
from .structs import *
from .sdklib import *

def encode_command_connection(cmd:CommandConnection)->tuple[int, bytes]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeCommandConnection(ctypes.byref(cmd), buf)

def encode_command_disconnect(cmd: CommandDisconnect)->tuple[int, bytes]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeCommandDisconnect(ctypes.byref(cmd), buf)

def encode_command_hardware(cmd: CommandHardware)->tuple[int, bytes]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeCommandHardware(ctypes.byref(cmd), buf)

def encode_query_software(qry: QuerySoftware)->tuple[int, bytes]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeQuerySoftware(ctypes.byref(qry), buf)

def encode(msg: BCPMessage)->tuple[int, bytes]:
    buf = MessageBuffer()
    return lib.encode(ctypes.byref(msg), ctypes.byref(buf)), bytes(buf)
