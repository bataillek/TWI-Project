///************************************************************************/
///*                    TWI SLAVE PROGRAM - Receive from Master           */
///************************************************************************/
///************************************************************************\
//* This is a TWI  Slave  program  written  for the  XMEGA A  A3BU  XPLAIN *
//* The program  is designed to work with  the TWI  Master program written *
//* for the XMEGA A A1U PRO XPLAIN board. PC0 and PC1 should  be connected *
//* together  from one board to another. When run, the  program  will wait *
//* for an interrupt to  receive data from the master. Upon  reception the *
//* slave program should  receive the data  and prepare a  packet with the *
//* received data incremented by 1. The master program should then request *
//* a read operation where the slave sends the updated data. Optimal break *
//* points have been marked with comments in the program.					 *
//\************************************************************************/
///************************************************************************\
//* To include from ASF:                                                   *
//*	% Default (Generic Board Support, GPIO, IOPORT						 *
//*	% System Clock Control (service)									 *
//*	% TWI - Two-wire Interface (driver) both							 *
//\************************************************************************/
//
//#include <asf.h>
//
//#define TWI_SLAVE_ADDR 0x60	//set the slave address to be stored in SLAVE register
//#define TWI_SPEED 5000
//#define PATTERN_TEST_LENGTH sizeof(test_pattern)
//// Define the TWI to be used
//#define TWI_SLAVE TWIC		//select the TWI module of the microcontroller
//
//// Initialise a test pattern
//volatile uint8_t test_pattern[] = {
	//0x55,
	//0xA5
//};
//
//// Initialise buffers for receiving and transmitting Data
//volatile uint8_t rx_pattern[TWIS_SEND_BUFFER_SIZE] = {0};
//volatile uint8_t m_rx_pattern[TWIS_SEND_BUFFER_SIZE] = {0};
//
//// Initialise a slave structure (note case sensitivity)
//TWI_Slave_t slave;
//
//// Setup a user flag, its use will become clear later on
//volatile Bool tx_in_progress_f = false;
//
//// Setup a slave process, the process is accessed each time a byte is received
//static void slave_process(void)
//{
	//tx_in_progress_f = true;
//}
//
//// The ISR is accessed each time a byte is received
//ISR(TWIC_TWIS_vect)
//{
	//TWI_SlaveInterruptHandler(&slave);
//}
//
//void twi_slave_init(	TWI_Slave_t *twi, TWI_t *module,void (*processDataFunction) (void),uint8_t address,
//TWI_SLAVE_INTLVL_t intLevel) {
	//uint8_t i=0;
	//
	///*initialise the slave module by setting:
		//slave structure to define the different data patterns and status, 
		//module to serve as a slave i.e TWIx {C,D,E,F}, 
		//slave call function i.e. specify a process for slave, 
		//slave address (has to be compliant with master),
		//slave module interrupt level
	//*/
//
	//// Initialise Slave
	//for (i=0;i<TWIS_SEND_BUFFER_SIZE;i++)
	//{
		//twi->receivedData[i] = 0;
		////twi->sendData[i] - Used to specify the send data when a master reads
	//}
//
	//sysclk_enable_peripheral_clock(module);	//enable the TWI module
	//TWI_SlaveInitializeDriver(twi, module, processDataFunction);	//I2C driver
	//TWI_SlaveInitializeModule(twi,address,intLevel);	//set slave address and interrupt level
//}
//
//int main_pre (void)	//A sample main for data read from a Master
//{
	//sysclk_init();
	//board_init();
	//
	//uint8_t i=0;
	//
	//irq_initialize_vectors();
//
	//twi_slave_init(	&slave,
	//&TWI_SLAVE,
	//*slave_process,
	//TWI_SLAVE_ADDR,
	//TWI_SLAVE_INTLVL_MED_gc);
	//
	//cpu_irq_enable();
	//
	//while (1) {
		//
		//// Check transmission in progress flag
		//if(tx_in_progress_f)
		//{
			//// Wait for reception of whole packet
			//do{}while(slave.result!=TWIS_RESULT_OK);
			//for (i=0;i<TWIS_SEND_BUFFER_SIZE;i++)
			//{
				///************************************************************************/
				///* Copy received data and prepare data to be transmitted. Note that     */
				///* these two can be separated to be able to transmit independently of   */
				///* reception of data. However, for the purpose of this test/example     */
				///* program, the updating of the data to send was conducted immediately  */
				///* to avoid another for loop.                                           */
				///************************************************************************/
				//rx_pattern[i] = slave.receivedData[i];
			//};
			//LED_Toggle(LED0);				// toggle LED
			//// Reset Flag
			///*** Break Point ***/
			//tx_in_progress_f = false;
		//}
	//}
//}