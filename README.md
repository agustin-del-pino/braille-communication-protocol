# braille-communication-protocol

Braille Communication Protocol for Monica

# Protocol 

- Bidirectional communication, both sides can send commands and response to them.
- BCP Message, which is the format of the sending messages.
- The max length of the message is 255 bytes.
- Exists two kind of message: Commands and Responses.
- The commands are action.
- The responses are results or acknowledged of a command.
- Exists a generic ACK and generic error, both are responses to commands.

# Message Structure

The message follow the next structure and also all bytes are unsigned.

````
Len (1 byte)  | Class (1 byte) | Data (253 byte)

Len   Class  Data
0x05 | 0x00 | 0x01 0x01 0x00 0x00
````

- Len is the length of the message (doesn't include itself).
- Class is the message class.
- Data is the message data.

# Message Classes

In order to distinguish which messages are command from which are responses, the even numbers were took for
the first one and the odd numbers were took for the later.

## Connection Command

This command is used for establish a connection. The handshake must be end with a Connection Response.

| Class  | Id (1 byte)     | Version (3 bytes: Major-Minor-Patch)   |
| ------ | --------------- | -------------------------------------- |
| `0x00` | A connection id | The version of SDK used for the sender |

**Example**
```
0x00 0x01 0x01 0x00 0x00
```
This message translate into

```
Class: Connection Command
Connection ID: 1
Version: v1.0.0
```

## Disconnection Command
This command is used for close a connection. The response will be an ACK.

| Class  | Id (1 byte)     |
| ------ | --------------- |
| `0x02` | A connection id |

**Example**
```
0x02 0x01
```
This message translate into

```
Class: Disconnection Command
Connection ID: 1
```

## Hardware Configuration Command
This command is used for configure the hardware. The response will be an ACK.

| Class  | Id (1 byte)     | Cells Number (1 byte)          |
| ------ | --------------- | ------------------------------ |
| `0x04` | A connection id | The number of cells to be used |

**Example**
```
0x04 0x01 0x0A
```
This message translate into

```
Class: Hardware Configuration Command
Connection ID: 1
Cells Number: 10
```

## Software Configuration Command
This command is used for configure the software. The response will be an ACK.

The actions configs is an array of 120 bytes, each element indicates in which index is the action.

| Class  | Id (1 byte)     | Actions Config (120 bytes) |
| ------ | --------------- | -------------------------- |
| `0x06` | A connection id | The action config array    |

**Example**
```
0x06 0x01 0x01 0x00 0x00 0x02
```
This message translate into

```
Class: Software Configuration Command
Connection ID: 1
Actions Config: [0]: Action 1, [1]: Nothing, [2]: Nothing, [3]: Action 2
```

## Braille Write Command
This command is used for write braille on the cells. The response will be an ACK.

| Class  | Id (1 byte)     | Monica Braille Byte Array (252 byte) |
| ------ | --------------- | ------------------------------------ |
| `0x08` | A Connection Id | The text to write in MBB encoding    |

**Example**
```
0x08 0x01 0x05 0x03 0x27
```
This message translate into

```
Class: Braille Write Command
Connection ID: 1
MBB Array: 0x05 0x03 0x27 -> BCP 
```

## Braille Clear Command
This command is used for clear the cells. The response will be an ACK.

| Class  | Id (1 byte)     |
| ------ | --------------- |
| `0x0A` | A Connection Id |

**Example**
```
0x0A 0x01
```
This message translate into

```
Class: Braille Clear Command
Connection ID: 1
```

## User Action Command
This command is used for report an user action, total simultaneous actions are 120. The response will be an ACK.

| Class  | Id (1 byte)     | Action State (15 byte Left-Right)           |
| ------ | --------------- | ------------------------------------------- |
| `0x0B` | A Connection Id | Each bit represent one action (0 off, 1 on) |

**Example**
```
0x0B 0x01 0b10000101
```
This message translate into

```
Class: User Action Command
Connection ID: 1
Action State: State of 1, State of 3, State of 8 are reported as on. 
```

## Error Response
This response is used for report an error when a command was executed.

| Class  | Origin (1 byte)                  | Id (1 byte)     | Code (1 byte) |
| ------ | -------------------------------- | --------------- | ------------- |
| `0x01` | The class that produce the error | A Connection Id | Error's Code  |

**Example**
```
0x01 0x00 0x01 0x0A
```
This message translate into

```
Class: Error Response
Origin: Connection Command (0x00)
Connection ID: 1
Code: 10 (0x0A) 
```

## ACK Response
This response is used for report an ack when the command finished.

| Class  | Origin (1 byte)                  | Id (1 byte)     |
| ------ | -------------------------------- | --------------- |
| `0x03` | The class that produce the error | A Connection Id |

**Example**
```
0x03 0x04 0x01
```
This message translate into

```
Class: ACK Response
Origin: Hardware Configuration Command
Connection ID: 1
Code: 10 (0x0A) 
```

## Connection Response
This response is used for establish a connection.

| Class | Id (1 byte)     | Version (3 bytes: Major-Minor-Patch) |
| ----- | --------------- | ------------------------------------ |
| `0x0` | A connection id | The version of SDK used for Monica   |

**Example**
```
0x00 0x01 0x01 0x00 0x00
```
This message translate into

```
Class: Connection Command
Connection ID: 1
Version: v1.0.0
```

# Connection Handshake

```plantuml
participant Machine as mch
participant Monica as mon

mch->mon: Connection Command
mch<-mon: Connection Response
mch->mon: Hardware Configuration Command
mch<-mon: ACK Response
mch->mon: Software Configuration Command
mch<-mon: ACK Response
```