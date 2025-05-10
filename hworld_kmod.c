#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int EventHandler(struct module *inModule, int inEvent, void *inArg)
{
        // Set return code to 0
        int returnCode = 0;
 
        switch (inEvent)
        {
          case MOD_LOAD:
                uprintf("Hello, beautiful world! \n");
                break;
          case MOD_UNLOAD:
                uprintf("Goodbye, cruel world! \n");
                break;
          default:
                returnCode = EOPNOTSUPP;
                break;
        }
 
        return(returnCode);
}

static moduledata_t  moduleData = {
        "hworld_kmod",          // Module Name
        EventHandler,           // Event handler function name
        NULL                    // Extra data
};

DECLARE_MODULE(hworld_kmod, moduleData, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
