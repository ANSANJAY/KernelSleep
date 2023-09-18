unsigned long msleep_interruptible(unsigned int msecs);

	will put the process into interruptible sleep

Return value : 

	Normally 0

	If the process is awakened early, then the return value is number of milliseconds remaining in the
	original requested sleep period
