workspace(name = "awesome-cpp")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Benchmark 1.8.0
http_archive(
    name = "com_github_google_benchmark",
    strip_prefix = "benchmark-1.8.0",
    url = "https://github.com/google/benchmark/archive/refs/tags/v1.8.0.zip",
)

# GoogleTest is required by Google Benchmark for testing
http_archive(
    name = "com_github_google_googletest",
    strip_prefix = "googletest-release-1.11.0",
    url = "https://github.com/google/googletest/archive/release-1.11.0.zip",
)
