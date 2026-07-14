def binary_to_printf(binary_lines):
    output = []

    for line in binary_lines:
        line = line.strip()

        if not line:
            continue

        if len(line) != 32 or any(c not in "01" for c in line):
            raise ValueError(f"Invalid instruction: {line}")

        # Convert binary to integer
        value = int(line, 2)

        # Convert to little-endian bytes
        little_endian = value.to_bytes(4, byteorder="little")

        # Format each byte as \xHH
        for byte in little_endian:
            output.append(f"\\x{byte:02x}")

    # Append four 0x00 bytes
    output.extend(["\\x00"] * 4)

    return f'printf "{"".join(output)}" > program.bin'


def main():
    print("RV32I Binary → printf Converter")
    print("Paste one 32-bit binary instruction per line.")
    print("Press Enter on an empty line to generate.")
    print("Type 'exit' or 'quit' as the first line to quit.\n")

    while True:
        instructions = []

        while True:
            line = input()

            # Exit only if it's the first thing typed
            if not instructions and line.strip().lower() in ("exit", "quit"):
                print("Sayonara!")
                return

            if line.strip() == "":
                break

            instructions.append(line)

        if not instructions:
            print("No instructions entered.\n")
            continue

        try:
            print()
            print(binary_to_printf(instructions))
        except ValueError as e:
            print(f"Error: {e}")

        print()  # Blank line before the next iteration


if __name__ == "__main__":
    main()