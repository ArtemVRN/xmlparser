
/*
 * 
 * Этот файл объявляет ключевые типы и функции парсера
 * 
 */

#ifndef XMLPARSER_H
#define XMLPARSER_H


#include <stdio.h>


/*** Атрибут тега ***/
typedef struct XmlAttribute
{
  
  char* name;
  char* value;
  
  struct Attribute* next;
  
} XmlAttribute;


/*** Сегмент значения: <sometag>  {valueaegment: <anothertag>, text, another_valuesegment}  </sometag> ***/
typedef struct XmlTag;
typedef struct XmlValueSegment
{
  
  struct XmlTag* tag;
  char* text;
  
  struct XmlValueSegment* next;
  
} XmlValueSegment;

/*** Тег ***/
typedef struct XmlTag
{
  
  char* name;
  
  XmlAttribute* attributesList;

  XmlValueSegment* value; 
  
} XmlTag;


/*** Документ ***/
struct XmlDocument
{
  
  char* name;
  char* version;
  
  XmlTag root;
  
};



XmlDocument*	 getDocument(const char* filename);
XmlDocument*	 getDocument(const FILE* instream);

XmlTag*		 getTag(const FILE* instream);

XmlAttribute*	 getAttributes(const FILE* instream);

XmlValueSegment* getXmlValueSegment(const FILE* instream);








#endif
