load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "static_allocator",
    srcs = [
    ],
    hdrs = [
        "object_pool.hpp",
        "static_allocator.hpp",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "static_allocator_test",
    srcs = [
        "static_allocator_test.cpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":static_allocator",
        "@com_google_googletest//:gtest_main",
    ],
)
