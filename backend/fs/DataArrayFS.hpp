// Copyright (c) 2013 - 2015, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.
//
// Authors: Christian Kellner <kellner@bio.lmu.de>
//          Jan Grewe <jan.grewe@g-node.org>

//TODO convenience methods for accessing dimensionality and shape of data

#ifndef NIX_DATAARRAYFS_HPP
#define NIX_DATAARRAYFS_HPP

#include <nix/base/IDataArray.hpp>
#include "EntityWithSourcesFS.hpp"

#include <boost/multi_array.hpp>
#include "Directory.hpp"

namespace nix {
namespace file {


class DataArrayFS : virtual public base::IDataArray,  public EntityWithSourcesFS {

private:

    static const NDSize MIN_CHUNK_SIZE;
    static const NDSize MAX_SIZE_1D;

    Directory dimensions;

    void setDtype(nix::DataType dtype);
public:

    /**
     * Standard constructor for existing DataArrays
     */
    DataArrayFS(const std::shared_ptr<base::IFile> &file, const std::shared_ptr<base::IBlock> &block, const std::string &loc);

    /**
     * Standard constructor for new DataArrays
     */
    DataArrayFS(const std::shared_ptr<base::IFile> &file, const std::shared_ptr<base::IBlock> &block, const std::string &loc,
                const std::string &id, const std::string &type, const std::string &name);

    /**
     * Standard constructor for new DataArrays that preserves the creation time.
     */
    DataArrayFS(const std::shared_ptr<base::IFile> &file, const std::shared_ptr<base::IBlock> &block, const std::string &loc,
                const std::string &id, const std::string &type, const std::string &name, time_t time);

    //--------------------------------------------------
    // Element getters and setters
    //--------------------------------------------------


    boost::optional<std::string> label() const;


    void label(const std::string &label);


    void label(const none_t t);


    boost::optional<std::string> unit() const;


    void unit(const std::string &unit);


    void unit(const none_t t);


    boost::optional<double> expansionOrigin() const;


    void expansionOrigin(double expansion_origin);


    void expansionOrigin(const none_t t);


    void polynomCoefficients(const std::vector<double> &polynom_coefficients);


    std::vector<double> polynomCoefficients() const;


    void polynomCoefficients(const none_t t);


    //--------------------------------------------------
    // Methods concerning dimensions
    //--------------------------------------------------

    ndsize_t dimensionCount() const;


    std::shared_ptr<base::IDimension> getDimension(ndsize_t id) const;


    std::shared_ptr<base::ISetDimension> createSetDimension(ndsize_t id);


    std::shared_ptr<base::IRangeDimension> createRangeDimension(ndsize_t id, const std::vector<double> &ticks);


    std::shared_ptr<base::IRangeDimension> createAliasRangeDimension();


    std::shared_ptr<base::ISampledDimension> createSampledDimension(ndsize_t id, double sampling_interval);


    bool deleteDimension(ndsize_t id);

    //--------------------------------------------------
    // Other methods and functions
    //--------------------------------------------------


    virtual ~DataArrayFS();


    //--------------------------------------------------
    // Methods concerning data access.
    //--------------------------------------------------

    virtual void createData(DataType dtype, const NDSize &size);


    bool hasData() const;


    void write(DataType dtype, const void *data, const NDSize &count, const NDSize &offset);


    void read(DataType dtype, void *buffer, const NDSize &count, const NDSize &offset) const;


    NDSize dataExtent(void) const;


    void   dataExtent(const NDSize &extent);


    DataType dataType(void) const;

};


} // namespace file
} // namespace nix

#endif //NIX_DATAARRAYFS_HPP
