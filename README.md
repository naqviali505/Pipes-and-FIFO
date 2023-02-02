# Pipes-and-FIFO
Pipes

This task creates a named pipe ‘mStreamChannel’. On the writing end, the Writer sends about 580000 integers to the pipe. The data is not to send as a whole. Your job is to send the data in the following format. 
MaxIterations = 5000
ChunkSize = 29
IntegerPerChunks=4
Interval (Microsecond)=250 
Interval to be append after each iteration. 

On the reader end, Now read these 580000 integers, show their count, and find the total prime numbers in them.

FIFO

Create a Program such that Parent Sends the series of message to child. 
The format is like [‘Send email to Ahmed’, ‘My password is 123’,’Hey to everyone’]
The format is list of strings. The child job is to encrypt messages and send them back to parent. At the end of the program, parent do have encrypted and original messages. 
