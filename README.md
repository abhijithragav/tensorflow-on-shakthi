| **`Documentation`** |
|-----------------|
## Pre-requisites 

Download pre-built RISC-V gnu tools from SiFive:
```
curl -O -L "https://static.dev.sifive.com/dev-tools/riscv64-unknown-elf-gcc-20181030-x86_64-linux-ubuntu14.tar.gz"
```
```
tar xzf riscv64-unknown-elf-gcc-20181030-x86_64-linux-ubuntu14.tar.gz
```
```
export PATH=${PATH}:riscv64-unknown-elf-gcc-20181030-x86_64-linux-ubuntu14/bin/
```

## Steps to Generate the Shakthi E-Class Compatible Binary

Clone the Reporsitory and checkout the "riscv_mcu" branch
```
git clone https://github.com/abhijithragav/tensorflow-on-shakthi.git && cd tensorflow-on-shakthi
```
```
git checkout riscv_mcu
```
Download the dependencies by running:
```tensorflow/lite/experimental/micro/tools/make/download_dependencies.sh.```

Build and Shakthi E-Class compatible Binary using:
```make -f tensorflow/lite/experimental/micro/tools/make/Makefile TARGET=riscv32_mcu```

## Testing the Binary on Shakthi E-Class simulator

https://gitlab.com/shaktiproject/cores/e-class


## License

[Apache License 2.0](LICENSE)
