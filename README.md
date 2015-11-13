# Project goal

SK Zero copy project
This project is a very fast packet receive from kernel space or send from userspace.
Both are implemented as a single kernel module for Linux.

This project have the same goal with netmap.
you can check the link http://info.iet.unipi.it/~luigi/netmap/ for the project goal.

I think my design is more easy to use.

Please check the patch e1000_2.6.32-504.3.3-modify.patch

So you have seen, just need modify the all_skb free_skb and receive_skb interface.

Here is another project, this project just need modify kernel code, it needn't change any NIC driver code.
I hope kernel upstream can merge or generate a standard for package zero copy.
https://github.com/Super-King/sk_zcp_kernel

# Dir introduce
driver: including zero copy driver, modify e1000 and original driver
example: including send forward and recive sample program.
include: using for application head file.
lib:     using for application lib file.

# Test ENV
kernel 2.6.32-504.3.3.el6.x86_64 test passed.

# Function
Support specify NICs to receive and send packets. Reference the example dir.

# Compile
make
