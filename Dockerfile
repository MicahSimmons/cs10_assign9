FROM ubuntu:latest

RUN apt-get update && apt-get -y install cmake
RUN apt-get -y install g++
RUN apt-get -y install gdb


COPY . .

WORKDIR ./queues

#CMD [ "/usr/bin/bash" ]
#CMD [ "./doit" ]