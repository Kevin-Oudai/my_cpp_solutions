# Multi-stage build for this specific exercise.
FROM gcc:13 AS build

WORKDIR /app
COPY . .

# Build all cpp sources in this exercise folder.
RUN g++ -std=c++17 -O2 *.cpp -o /usr/local/bin/exercise14_1

FROM gcc:13
COPY --from=build /usr/local/bin/exercise14_1 /usr/local/bin/exercise14_1
WORKDIR /app
ENTRYPOINT ["/usr/local/bin/exercise14_1"]
