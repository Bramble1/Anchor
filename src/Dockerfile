FROM debian:latest

ENV DEBIAN_FRONTEND=noninteractive

#updates and upgrades
RUN apt update -y && apt upgrade -y



#create a new user
RUN useradd -ms /bin/bash sam

#create working directory inside container
WORKDIR /home/sam


USER sam

COPY anchor .



