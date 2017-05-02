#ifdef DEBUG
#define DebugInt(info,x) do{printf("[Debug]"info);printf(": %d\n",x);}while(0)
#define DebugStr(info,x) do{printf("[Debug]"info);printf(": \"%s\"\n",x);}while(0)
#define PAUSE() system("pause")
#else
#define DebugInt(info,x) do{}while(0)
#define DebugStr(info,x) do{}while(0)
#define PAUSE() do{}while(0)
#endif
