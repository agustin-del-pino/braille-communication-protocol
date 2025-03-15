import bcpsdk

cmd = bcpsdk.CommandConnection()
cmd.id = 5
cmd.version = b'\x01\x00\x00'

b, l = bcpsdk.encode_command_connection(cmd)

print(l, b)