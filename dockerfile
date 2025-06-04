FROM ubuntu:25.10

# Install necessary packages
RUN DEBIAN_FRONTEND=noninteractive \
    apt-get update \
    && apt-get install -y wget bzip2 make unzip cppcheck git

WORKDIR /home/ubuntu