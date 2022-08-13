const std = @import("std");

// Special entry point which is called by `zig build`.
pub fn build(b: *std.build.Builder) void {
    // ^^^ function should create a DAG of std.build.Step nodes.
    // Each Step node executes a part of the build process.
    // Each Step may have a set of dependencies which need to made before the
    //   Step itself can be made. You can invoke named steps via:
    //   `zig build <step_name>`. Steps install and uninstall are provided by
    //   default.
    // `zig build --help`.
    // Step has the same interface pattern as std.mem.Allocator and requires the
    //   implementation of a single `make` function which is invoked when the
    //   Step is made.
    const named_step = b.step("foo-step", "Help text here.");

    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("customise_macos", "src/main.zig");
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();

    const run_cmd = exe.run();
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const exe_tests = b.addTest("src/main.zig");
    exe_tests.setTarget(target);
    exe_tests.setBuildMode(mode);

    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&exe_tests.step);
}
