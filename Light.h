#ifndef __LIGHT_H__
#define __LIGHT_H__

class Light
{
public:
  Light();

  int count = 36;

  pinMap pins[36] = {
    {"kitchen/main", 22, 'D'},
    {"kitchen/bar", 22, 'D'},
    {"kitchen/workZone", 22, 'D'},
    
    {"kitchen/workZoneR", 2, 'A'},
    {"kitchen/workZoneG", 3, 'A'},
    {"kitchen/workZoneB", 4, 'A'},
    
    {"corridor/main", 8, 'D'}, 
    {"corridor/hallway", 8, 'D'},
    {"corridor/stairs", 8, 'D'},
    {"corridor/wardrobe", 8, 'D'},
    {"corridor/2nd", 8, 'D'},
    
    {"stairs/1st", 8, 'D'},
    {"stairs/2nd", 8, 'D'},
    
    {"livingroom/Small", 9, 'D'},
    {"livingroom/Big", 10, 'D'},
    {"livingroom/Led", 11, 'D'},
    
    {"livingroom/LedR", 12, 'A'},
    {"livingroom/LedG", 13, 'A'},
    {"livingroom/LedB", 14, 'A'},
    
    {"bathroom1/main", 9, 'D'},
    {"bathroom1/mirrow", 9, 'D'},
    {"bathroom1/fan", 9, 'D'},
    
    {"bathroom2/main", 9, 'D'},
    {"bathroom2/mirrow", 9, 'D'},
    {"bathroom2/fan", 9, 'D'},
    
    {"bedroom/main", 8, 'D'},
    {"bedroom/secondary", 8, 'D'},
    {"bedroom/bedsideLeft", 8, 'D'},
    {"bedroom/bedsideRight", 8, 'D'},
    {"bedroom/wardrobe", 8, 'D'},
    {"terrace/main", 8, 'D'},

    {"childrens/main", 8, 'D'},
    {"childrens/secondary", 8, 'D'},
    
    {"guest/main", 8, 'D'},
    {"guest/secondary", 8, 'D'},

    {"3rd/wardrobe", 8, 'D'},    
  };

  void ModuleHandler( String id, String val );
  void setup();

//private:
  void setPin( String id, int val );
  void SetValue( String id, String val );
  void SetValue( String id, long val );
  void SetCopmplexValue( String id, String val );
  void SetColor( String id, String color );

};

#endif
