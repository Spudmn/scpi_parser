#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	const int16_t errno;
	const char *msg;
} SCPI_error_desc;

/** User error definitions */
extern const SCPI_error_desc scpi_user_errors[];


/**
 * Callback when error is added to the queue
 *
 * @param errno error code
 * @param msg error string in the canonical format <code>,<message>
 */
extern __attribute__((weak))
void scpi_user_error(int16_t errno, const char * error_string);


// SCPI error constants
enum {
	E_NO_ERROR = 0,
	E_COMMAND_ERROR = -100,
	E_CMD_INVALID_CHARACTER = -101,
	E_CMD_SYNTAX_ERROR = -102,
	E_CMD_INVALID_SEPARATOR = -103,
	E_CMD_DATA_TYPE_ERROR = -104,
	E_CMD_GET_NOT_ALLOWED = -105,
	E_CMD_PARAMETER_NOT_ALLOWED = -108,
	E_CMD_MISSING_PARAMETER = -109,
	E_CMD_COMMAND_HEADER_ERROR = -110,
	E_CMD_HEADER_SEPARATOR_ERROR = -111,
	E_CMD_PROGRAM_MNEMONIC_TOO_LONG = -112,
	E_CMD_UNDEFINED_HEADER = -113,
	E_CMD_HEADER_SUFFIX_OUT_OF_RANGE = -114,
	E_CMD_UNEXPECTED_NUMBER_OF_PARAMETERS = -115,
	E_CMD_NUMERIC_DATA_ERROR = -120,
	E_CMD_INVALID_CHARACTER_IN_NUMBER = -121,
	E_CMD_EXPONENT_TOO_LARGE = -123,
	E_CMD_TOO_MANY_DIGITS = -124,
	E_CMD_NUMERIC_DATA_NOT_ALLOWED = -128,
	E_CMD_SUFFIX_ERROR = -130,
	E_CMD_INVALID_SUFFIX = -131,
	E_CMD_SUFFIX_TOO_LONG = -134,
	E_CMD_SUFFIX_NOT_ALLOWED = -138,
	E_CMD_CHARACTER_DATA_ERROR = -140,
	E_CMD_INVALID_CHARACTER_DATA = -141,
	E_CMD_CHARACTER_DATA_TOO_LONG = -144,
	E_CMD_CHARACTER_DATA_NOT_ALLOWED = -148,
	E_CMD_STRING_DATA_ERROR = -150,
	E_CMD_INVALID_STRING_DATA = -151,
	E_CMD_STRING_DATA_NOT_ALLOWED = -158,
	E_CMD_BLOCK_DATA_ERROR = -160,
	E_CMD_INVALID_BLOCK_DATA = -161,
	E_CMD_BLOCK_DATA_NOT_ALLOWED = -168,
	E_CMD_EXPRESSION_ERROR = -170,
	E_CMD_INVALID_EXPRESSION = -171,
	E_CMD_EXPRESSION_DATA_NOT_ALLOWED = -178,
	E_CMD_MACRO_ERROR = -180,
	E_CMD_INVALID_OUTSIDE_MACRO_DEFINITION = -181,
	E_CMD_INVALID_INSIDE_MACRO_DEFINITION = -183,
	E_CMD_MACRO_PARAMETER_ERROR = -184,
	E_EXECUTION_ERROR = -200,
	E_EXE_INVALID_WHILE_IN_LOCAL = -201,
	E_EXE_SETTINGS_LOST_DUE_TO_RTL = -202,
	E_EXE_COMMAND_PROTECTED = -203,
	E_EXE_TRIGGER_ERROR = -210,
	E_EXE_TRIGGER_IGNORED = -211,
	E_EXE_ARM_IGNORED = -212,
	E_EXE_INIT_IGNORED = -213,
	E_EXE_TRIGGER_DEADLOCK = -214,
	E_EXE_ARM_DEADLOCK = -215,
	E_EXE_PARAMETER_ERROR = -220,
	E_EXE_SETTINGS_CONFLICT = -221,
	E_EXE_DATA_OUT_OF_RANGE = -222,
	E_EXE_TOO_MUCH_DATA = -223,
	E_EXE_ILLEGAL_PARAMETER_VALUE = -224,
	E_EXE_OUT_OF_MEMORY = -225,
	E_EXE_LISTS_NOT_SAME_LENGTH = -226,
	E_EXE_DATA_CORRUPT_OR_STALE = -230,
	E_EXE_DATA_QUESTIONABLE = -231,
	E_EXE_INVALID_FORMAT = -232,
	E_EXE_INVALID_VERSION = -233,
	E_EXE_HARDWARE_ERROR = -240,
	E_EXE_HARDWARE_MISSING = -241,
	E_EXE_MASS_STORAGE_ERROR = -250,
	E_EXE_MISSING_MASS_STORAGE = -251,
	E_EXE_MISSING_MEDIA = -252,
	E_EXE_CORRUPT_MEDIA = -253,
	E_EXE_MEDIA_FULL = -254,
	E_EXE_DIRECTORY_FULL = -255,
	E_EXE_FILE_NAME_NOT_FOUND = -256,
	E_EXE_FILE_NAME_ERROR = -257,
	E_EXE_MEDIA_PROTECTED = -258,
	E_EXE_EXPRESSION_ERROR = -260,
	E_EXE_MATH_ERROR_IN_EXPRESSION = -261,
	E_EXE_MACRO_ERROR = -270,
	E_EXE_MACRO_SYNTAX_ERROR = -271,
	E_EXE_MACRO_EXECUTION_ERROR = -272,
	E_EXE_ILLEGAL_MACRO_LABEL = -273,
	E_EXE_MACRO_PARAMETER_ERROR = -274,
	E_EXE_MACRO_DEFINITION_TOO_LONG = -275,
	E_EXE_MACRO_RECURSION_ERROR = -276,
	E_EXE_MACRO_REDEFINITION_NOT_ALLOWED = -277,
	E_EXE_MACRO_HEADER_NOT_FOUND = -278,
	E_EXE_PROGRAM_ERROR = -280,
	E_EXE_CANNOT_CREATE_PROGRAM = -281,
	E_EXE_ILLEGAL_PROGRAM_NAME = -282,
	E_EXE_ILLEGAL_VARIABLE_NAME = -283,
	E_EXE_PROGRAM_CURRENTLY_RUNNING = -284,
	E_EXE_PROGRAM_SYNTAX_ERROR = -285,
	E_EXE_PROGRAM_RUNTIME_ERROR = -286,
	E_EXE_MEMORY_USE_ERROR = -290,
	E_EXE_OUT_OF_MEMORY_291 = -291,
	E_EXE_REFERENCED_NAME_DOES_NOT_EXIST = -292,
	E_EXE_REFERENCED_NAME_ALREADY_EXISTS = -293,
	E_EXE_INCOMPATIBLE_TYPE = -294,
	E_DEVICE_SPECIFIC_ERROR = -300,
	E_DEV_SYSTEM_ERROR = -310,
	E_DEV_MEMORY_ERROR = -311,
	E_DEV_PUD_MEMORY_LOST = -312,
	E_DEV_CALIBRATION_MEMORY_LOST = -313,
	E_DEV_SAVE_RECALL_MEMORY_LOST = -314,
	E_DEV_CONFIGURATION_MEMORY_LOST = -315,
	E_DEV_STORAGE_FAULT = -320,
	E_DEV_OUT_OF_MEMORY = -321,
	E_DEV_SELF_TEST_FAILED = -330,
	E_DEV_CALIBRATION_FAILED = -340,
	E_DEV_QUEUE_OVERFLOW = -350,
	E_DEV_COMMUNICATION_ERROR = -360,
	E_DEV_PARITY_ERROR_IN_PROGRAM_MESSAGE = -361,
	E_DEV_FRAMING_ERROR_IN_PROGRAM_MESSAGE = -362,
	E_DEV_INPUT_BUFFER_OVERRUN = -363,
	E_DEV_TIME_OUT_ERROR = -365,
	E_QUERY_ERROR = -400,
	E_QUERY_INTERRUPTED = -410,
	E_QUERY_UNTERMINATED = -420,
	E_QUERY_DEADLOCKED = -430,
	E_QUERY_UNTERMINATED_AFTER_INDEFINITE_RESPONSE = -440,
	E_POWER_ON = -500,
	E_USER_REQUEST = -600,
	E_REQUEST_CONTROL = -700,
	E_OPERATION_COMPLETE = -800,
};



/**
 * Get SCPI error string:
 * <code>,"<message>[; <extra>]"
 *
 * @param buffer Buffer for storing the final string. Make sure it's big enough.
 * @param errno Error number
 * @param extra Extra information, appended after the generic message. Can be NULL.
 *
 * @returns actual error code. Code may be coerced to closest defined code (categories: tens, hundreds)
 */
int16_t scpi_error_string(char *buffer, int16_t errno, const char *extra);


/** Add error to the error queue */
void scpi_add_error(int16_t errno, const char *extra);


/** Get number of errors in the error queue */
uint8_t scpi_error_count(void);


/**
 * Read and remove one entry from the error queue.
 * Returns 0,"No error" if the queue is empty.
 *
 * The entry is copied to the provided buffer, which must be 256 chars long.
 */
void scpi_read_error(char *buf);


/** Read error, do not remove from queue */
void scpi_read_error_noremove(char *buf);
