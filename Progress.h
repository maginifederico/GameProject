/**
 * Project Untitled
 */


#ifndef _PROGRESS_H
#define _PROGRESS_H

class Progress {
public:
    bool unlockedLevels[];
    int coins;
    int healthLevel;
    int pataGunLevel;
    int pataShotLevel;
    int pataLauncherLevel;

    void setValues();
};

#endif //_PROGRESS_H