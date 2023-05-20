FROM alpine:latest

RUN apk --no-cache add cmake make g++ 

COPY . /usr/src/CppCMakeTemplate

WORKDIR /usr/src/CppCMakeTemplate

RUN set -ex && cmake -S . -B build 

WORKDIR /usr/src/CppCMakeTemplate/build/

RUN make

