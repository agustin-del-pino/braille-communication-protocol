import ctypes

MAX_MSG_LEN = 0xFF
MessageBuffer = ctypes.c_ubyte * MAX_MSG_LEN

# Define structures
class CommandConnection(ctypes.Structure):
    _fields_ = [
        ("id", ctypes.c_uint8),
        ("version", ctypes.c_char * 3),
    ]

class CommandDisconnect(ctypes.Structure):
    _fields_ = [
        ("id", ctypes.c_uint8),
    ]

class CommandHardware(ctypes.Structure):
    _fields_ = [
        ("cells", ctypes.c_uint8),
    ]

class QuerySoftware(ctypes.Structure):
    _fields_ = []  # Empty struct

# Define MessageData union
class MessageData(ctypes.Union):
    _fields_ = [
        ("CommandConnection", CommandConnection),
        ("CommandDisconnect", CommandDisconnect),
        ("CommandHardware", CommandHardware),
        ("QuerySoftware", QuerySoftware),
    ]

# Define BCPMessage structure
class BCPMessage(ctypes.Structure):
    _fields_ = [
        ("type", ctypes.c_uint8),
        ("data", MessageData),
    ]

__all__ = [
    "BCPMessage",
    "MessageData",
    "QuerySoftware",
    "CommandHardware",
    "CommandDisconnect",
    "CommandConnection",
    "MessageBuffer"
]