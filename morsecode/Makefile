MICROBIT_PATH = /media/tom/MICROBIT
MICROBIT_PATH1 = /media/tom/MICROBIT1

SOURCE_FILES += \
    source/main.cpp

OUTPUT_FILE = build/bbc-microbit-classic-gcc/source/iotmorsecode-combined.hex

run: ${OUTPUT_FILE}
	cp ${OUTPUT_FILE} ${MICROBIT_PATH}
	cp ${OUTPUT_FILE} ${MICROBIT_PATH1}

${OUTPUT_FILE}: ${SOURCE_FILES}
	yt target bbc-microbit-classic-gcc
	yt build