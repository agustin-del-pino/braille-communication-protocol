import ctypes
from .structs import *
from .sdklib import *

def encode_command_connection(cmd:CommandConnection)->tuple[int, bytes]:
    buf = MessageBuffer()
    return lib.encodeCommandConnection(ctypes.byref(cmd), ctypes.byref(buf)), bytes(buf)

def encode_command_disconnect(cmd: CommandDisconnect)->tuple[bytes, int]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeCommandDisconnect(ctypes.byref(cmd), buf)

def encode_command_hardware(cmd: CommandHardware)->tuple[bytes, int]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeCommandHardware(ctypes.byref(cmd), buf)

def encode_query_software(qry: QuerySoftware)->tuple[bytes, int]:
    buf = MessageBuffer()
    return bytes(buf), lib.encodeQuerySoftware(ctypes.byref(qry), buf)

def encode(msg: BCPMessage)->tuple[bytes, int]:
    buf = MessageBuffer()
    return bytes(buf), lib.encode(ctypes.byref(msg), ctypes.byref(buf))
