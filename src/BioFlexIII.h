#pragma once
#include <Arduino.h>

// inicia el serial, etc...
void BioFlexInit(int BioflexRX, int BioflexTX, int StartButton, int Power);

void BioFlexPowerOn(bool on);

// A Device identification
// Show device identification and software version. This command is suitable for
// communication start-up test.
String BioflexGetVersion();

// C Capture fingerprint
// Capture fingerprint from the sensor and store in RAM.
void CaptureFingerprint();

// R Enroll fingerprint into RAM
// Capture fingerprint and enroll fingerprint into RAM. It will take approx 2 seconds.
void EnrollFingerprintIntoRAM();

// V Verify with the RAM
// Verify the fingerprint against the template that stored in RAM.
void VerifyFingerprint();

// Y Delete template in RAM
// Erase the template from RAM.
// Response <CR><LF>
void DeleteTemplateInRAM();

// 0001 to 0999 Change template identity ID.
// Number specified a template storage slot in flash, it must be sent before command E
// and X. Templates stored on 0001 to 0099 will identify in 1:N command “ I ”.
// Response id=<ID><CR><LF>
void ChangeTemplateID(int ID);

// E Capture and enroll into flash memory slot (ID)
// Capture fingerprint and enroll fingerprint into flash memory where at the storage slot
// defined by <ID> number 000l to 0999. After enrollment the number of the storage slot,
// the response will also return at the end of the text string (see example below). It will
// take approx. 2 seconds to enroll fingerprint.
void EnrollFingerprintIntoFlash();

// I Identify against in flash memory slot 001 to 099
// Capture fingerprint and identify against templates (0001 to 0099) that are stored in the
// flash memory. On success the template storage slot ID is returned.
void Identification();

// X Delete template (ID) in flash memory slot
// Delete a pre-defined template in flash. The selected template storage slot must be
// specified by a slot number (0001 to 0999). After completed deletion, the number of
// the deleted slot is returned.
// Response: <CR> <LF>
void DeleteTemplate();

// DEL Delete all templates in flash memory slot
// All templates stored in flash memory are deleted
void DeleteAllTemplates();

// M Download template to RAM
// Download template to RAM from host. The command must start with M and then a
// binary sequence of 512 byte values. When the down1oad is completed, BioFlex IV
// returns. <CR> <LF>
// Response: <CR> <LF>
void DownloadTemplateToRAM();

// B Upload fingerprint raw image to host
// Upload fingerprint raw image that captured from sensor. The raw image is uploaded
// as a binary sequence of 45312 byte values. The image has 192columns (x) and 236
// rows (y).The first byte in the sequence is the upper left pixel and continues in
// column-direction.
// Response:
// Binary sequence of 45312 bytes <CR> <LF>
void UploadFingerprintRawImage();

// T Upload the template from flash memory slot (ID)to host
// Upload template that stored in flash slot(ID) to host. The template is uploaded as a
// binary sequence of 512 byte values.
// Response:
// Binary sequence of 512 bytes <CR> <LF>
void UploadTemplateFromFlash();

// S Upload the enrollment table to host
// Upload the enrollment table to host. In the enrollment table, ‘f’: enrolled, ‘e’: empty
// Response:
// Binary sequence of 999 bytes <CR> <LF>
// Example:
// feeeeefeeeeeeeeeeeeeeffeeeeeee...eeeeef<CR><LF>
void UploadEnrollmentTable();

// L Security level setup
// The default security level is ‘L1’ after power on. The user can setup the fingerprint
// match threshold from ‘L1’ to ‘L9’.
// Response: <CR> <LF>
void SecurityLevelSetup();

// O Verify against in flash memory slot in location (ID)
// Capture fingerprint and verify against the template (ID) that stored in the flash
// memory. On success the template storage slot ID is returned.
void Verification();

// K Move template from RAM to flash memory
// Write RAM data to flash memory slot location (ID)
// Move template from RAM to flash memory slot. The selected template storage slot
// must be specified by a slot number (0001 to 0999 ).
void MoveTemplateFromRAMToFlash();

// J Upload a condensed fingerprint raw image to host
// Upload a condensed fingerprint raw image that captured from sensor. The raw image
// is uploaded as a binary sequence of 2496 byte values. The image has 48columns (x)
// and 52 rows (y).The first byte in the sequence is the upper left pixel and continues in
// column-direction.
// Response:
// Binary sequence of 2496 bytes <CR> <LF>
void UploadCondensedFingerprintRawImage();

// F Change UART baud rate and control LED on/off
// Users can use “F” command to change UART baud rate and control LED on/off.
// The default baud rate is 115200 bps in factory. The new baud rate will be available
// after reset the power.”FB1” “FB2” “FB2” & “FB3” functions will be activated after
// reset the power.
// FB1 Change UART Baud Rate to 9600 bps and store a flag in
// FB2 Change UART Baud Rate to19200 bps and store a flag in
// FB3 Change UART Baud Rate to 57600 bps and store a flag in
// FB4 Change UART Baud Rate to 115200 bps and store a flag in
void ChangeUARTBaud();

// FE1 Change LED control by external command and store a flag
// FE2 Change LED control by BioFlex itself and store a flag in
// -Left Leds-
// FL1 Orange On
// FL2 Red    On
// FL3 Green  On
// FL4 Orange Off
// FL5 Red    Off
// FL6 Green  Off
// -Right Leds-
// FR1 Orange on
// FR2 Red    on
// FR3 Green  on
// FR4 orange off
// FR5 Red    off
// FR6 Green  off
void ControlLED();
