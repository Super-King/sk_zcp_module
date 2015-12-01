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

# 简单介绍
1. 工程利用mmap，将网卡驱动的内存空间映射到用户空间。这样用户态可以直接访问到原始的数据包，避免了内核和用户态的两次拷贝。
2. 利用预先分配的固定大小的buff来保存数据包。这样减少了内核原有的动态分配。
3. 接收和发送数据包无需任何系统调用。
4. 可以单独指定同一型号的不同网卡作为零拷贝驱动的网卡。
5. 支持开启协议栈数据包拷贝功能，就是数据包递交到用户空间的同时，还会拷贝一份发送给kernel协议栈。 

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
