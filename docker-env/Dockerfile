### This creates the base image for the Build and Test Environment for CADG

# Get the base Ubuntu image from Docker Hub
FROM ubuntu:18.04

# Add ubuntu toolchain repository
RUN apt-get -qq -d update
RUN apt-get install -qq -y software-properties-common
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt-get -qq -d update

# Install tools
RUN apt-get -qq -y install \
    cmake \
    cppcheck \
    g++-6 \
    git \
    libasio-dev \
    libboost-all-dev \
    libcpprest-dev \
    libspdlog-dev \
    nano \
    software-properties-common \
    wget

# Make g++ 6 the default g++ executable
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90

WORKDIR /usr/src/micro-service

### Concludes base image
