FROM ubuntu:22.04

RUN apt update && \
    apt install -y gcc valgrind make check lcov && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir /home/school
WORKDIR /home/school




