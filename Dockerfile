# Get the base test environment image from Docker Hub
FROM micro-services-env

# Set the working directory
WORKDIR "/usr/src/mycpprest"

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . .

RUN mkdir build
WORKDIR "/usr/src/mycpprest/build"

RUN cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ..
RUN make

CMD ["./mycpprest"]
