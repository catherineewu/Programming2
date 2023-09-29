/** BINARY FILE IO:
 *
 * BINARY VS. TEXT IO OPERATIONS
 * TEXT FILE: deal with conversations, convert data to text representations
 * Data processed into/out of a stream
 * For example, writing integers into the file writes separate text characters for each digit
 *
 * BINARY FILE: direct transfer of data from memory to a file or reverse
 * No conversion, copying bytes, faster transfer, smaller file sizes
 * Binary files (.bin) have various appearances as string of characters, numbers, and spaces
 * Not meant to be read by humans but by code
 *
 * BYTE: basic data form made up of 8 bits (1 or 0)
 * Integers 4 byte data types (or pairs of 4-bit values)
 * Characters <= 1 byte/character - many ways of encoding file to different character sizes
 * Multi-byte values are not standardized
 *
 * BIG-ENDIAN & LITTLE-ENDIAN
 * ex: 1285 numeric value
 * Big-endian: "Big" end (greatest place value) written first - 1285
 * Little-endian: "Little" end (smallest place value) written first - 5821
 * Most computer architectures store in little-endian
 * Won't affect directly in course since binary operators will copy bytes in proper order regardless of platform
 *
 * BINARY FILE FORMAT
 * Don't have visible format (no delimiters, newline characters, etc.)
 * All data on one "line" or stream of bytes, data extracted according to byte counts specified
 * Though there is no format, binary files still have structure
 *
 * DETERMINING FILE STRUCTURE
     * 1) Know structure because you made it 2) Read about about it through documentation
     * Harder way if unknown - reverse engineering (guesswork)
     * STATIC FORMATS: Set and known number and order of data types.
         * Ex: a file with known integer, then a flaot, then another integer
     * DYNAMIC FILES: Reading files with unknown length, data type, or other feature of the file that affects data reading
         * Ex: a file with a starting integer then varying numbers of floats
         * SOLUTION: Data, to describe other data
         * Some count data added to file (ex: 2-byte short, limited int data type with range +-32,768)
         * 2-STEP PROCESS: 1) Write AMOUNT of data 2) Write each element of the data (substeps for complex objects) */

// EX: When creating dynamic file...
void WriteDataToFile(float* theData, short count) {
    // 1) Write count
    // 2) for (count)
    //      write theData[i];}
}

/** READING DATA W/COUNTERS
 * When reading file, made to be short, but can also decide to use int, long, etc.
 * short counter = Read2BytesFromFile();  // not a real function
 * float myData[counter]; variable length arrays not valid in C++
 * float *myData = new float[counter];
 * for (int i = 0; i < counter; i++)
 *      myData[i] = Read4BytesFromFile();  // not a real function
 *
 * FILES WITH MIXED DATA:
 * File description with chart of bytes and description of data (including counts)
 * Each piece of data has description of purposes, how to use, etc.
 * Size of data, whether set or determined by counts, is essential in binary.
 */

/** PART 2: BINARY FILE IO IN C++
 * CLASSES & FUNCTIONS: same as text-based input
 * ofstream (output), ifstream (input), fstream (input and/or output)
 * FileName.open()  //
 *
 *
 */

