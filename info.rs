use std::fs;

fn get_rythonz_version() {
    println!("Rythonz Version: 1.0.0");
}

fn get_environment() {
    println!("Environment: Development");
}

fn main() {
    println!("--- CPU Information ---");
    if let Ok(cpu_info) = fs::read_to_string("/proc/cpuinfo") {
        println!("{}", cpu_info);
    } else {
        println!("Failed to read /proc/cpuinfo");
    }

    println!("--- Memory Information ---");
    if let Ok(mem_info) = fs::read_to_string("/proc/meminfo") {
        println!("{}", mem_info);
    } else {
        println!("Failed to read /proc/meminfo");
    }

    println!("--- System Information ---");
    if let Ok(version_info) = fs::read_to_string("/proc/version") {
        println!("{}", version_info);
    } else {
        println!("Failed to read /proc/version");
    }

    println!("--- Rythonz Information ---");
    get_rythonz_version();
    get_environment();

    // Add more sections as needed
}
