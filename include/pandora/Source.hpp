#ifndef PAN_SOURCE_H_INCLUDE
#define PAN_SOURCE_H_INCLUDE

#include <string>
#include <H5Cpp.h>

#include <pandora/NamedEntity.hpp>


namespace pandora {
class SourceIterator;
class SourceTreeIterator;

class Source : public NamedEntity{
private:
  Group sources;

public:

  Source(const Source &source);

  Source(File *file, Group group, std::string id);

  void parentSource(std::string parent_id);
  std::string parentSource() const;

  Source addSource(std::string name, std::string type);

  bool hasSource(std::string source_id, std::string type = "", uint depth = 0) const;

  Source findSource(std::string source_id, std::string type = "", uint depth = 0)const;

  bool removeSource(std::string id);

  size_t childCount() const;

  bool hasChildren() const;

  SourceTreeIterator treeIterator(std::string type = "", uint depth = 0) const;

  SourceIterator children(std::string type = "") const;

  virtual ~Source();

};
}//of namespace


#endif // HDX_SOURCE_H_INCLUDE