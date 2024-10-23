FROM manjarolinux/base

WORKDIR /usr/src

COPY main.c .

CMD [ "gcc main.c -o main && ./main" ]

LABEL version = 1.0.0
LABEL description = "a c programme that sort integers lists"
LABEL maintainer = "enekraftii"