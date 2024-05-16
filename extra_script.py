Import("env")

def generate_lst(source, target, env):
    elf_file = str(target[0])
    lst_file = elf_file.replace(".elf", ".lst")
    env.Execute(f"avr-objdump -h -S {elf_file} > {lst_file}")

env.AddPostAction("$BUILD_DIR/firmware.elf", generate_lst)