Implementation:	kernel/timer/timer.c

void msleep(unsigned int msecs)
{
        unsigned long timeout = msecs_to_jiffies(msecs) + 1;

        while (timeout)
                timeout = schedule_timeout_uninterruptible(timeout);
}


unsigned long msleep_interruptible(unsigned int msecs)
{
        unsigned long timeout = msecs_to_jiffies(msecs) + 1;

        while (timeout && !signal_pending(current))
                timeout = schedule_timeout_interruptible(timeout);
        return jiffies_to_msecs(timeout);
}

EXPORT_SYMBOL(msleep_interruptible);

include/linux/delay.h

static inline void ssleep(unsigned int seconds)
{
        msleep(seconds * 1000);
}

