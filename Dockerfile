#syntax=docker/dockerfile:1.4.0
FROM debian:bullseye

RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ git nodejs npm python3-pip time

WORKDIR /tmp

RUN git clone https://github.com/atcoder/ac-library.git
RUN mv ./ac-library/ /opt/

RUN pip install online-judge-tools
RUN npm install -g atcoder-cli

RUN cat <<EOF >> /usr/local/bin/check
#!/bin/sh
g++ -std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -I/opt/boost/gcc/include \
    -L/opt/boost/gcc/lib -I/opt/ac-library -o ./a.out ./Main.cpp && oj t
EOF

RUN chmod u+x /usr/local/bin/check
