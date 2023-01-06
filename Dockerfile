FROM ubuntu:20.04
RUN apt-get update
RUN apt-get install -y curl lsb-release wget software-properties-common gnupg make

WORKDIR /root

# install cmake 3.24.0
RUN curl --fail --silent --show-error --location -o cmake.sh https://github.com/Kitware/CMake/releases/download/v3.25.0/cmake-3.25.0-linux-x86_64.sh
RUN chmod u+x cmake.sh
RUN mkdir cmake
RUN ./cmake.sh --skip-licence --prefix=/root/cmake --exclude-subdir
RUN ln -s /root/cmake/bin/cmake /usr/bin/cmake

# install llvm 14
RUN curl --fail --silent --show-error --location -o llvm.sh https://apt.llvm.org/llvm.sh
RUN chmod u+x llvm.sh
RUN ./llvm.sh 14
ENV PATH="${PATH}:/usr/lib/llvm-14/bin"

# install cifuzz
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/CodeIntelligenceTesting/cifuzz/main/install.sh)"

# check versions
RUN cmake --version
RUN clang --version
RUN cifuzz --version

RUN mkdir /project
WORKDIR /project
COPY . .
