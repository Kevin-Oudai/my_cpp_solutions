# Multi-stage build to keep the runtime lean.
# TARGET points to any exercise directory containing C++ sources with a single main.
ARG TARGET=chapter_12/exercise12_36

FROM gcc:13 AS build
ARG TARGET

WORKDIR /app
COPY . .

WORKDIR /app/${TARGET}
RUN g++ -std=c++17 -O2 *.cpp -o /usr/local/bin/app

# Use the same base image as runtime to avoid libstdc++/glibcxx mismatches.
FROM gcc:13

COPY --from=build /usr/local/bin/app /usr/local/bin/app
WORKDIR /app
ENTRYPOINT ["/usr/local/bin/app"]
