/** @file filter.h
 *
 * Filter interface
 *
 */
#ifndef _FILTER_H_
#define _FILTER_H_

#include "../handest_defs.h"
#include <string>
#include <vector>

namespace handest {
	/// Filter interface
	class Filter {
	public:

		/// Name of the Filter
		virtual const std::string& getName() const = 0;

		/// Filter
		Point3D::Cloud& FilterPCL::FilterScene(Point3D::Cloud& input) const = 0;

		/// Virtual descrutor
		virtual ~Filter() {}
	};
};

#endif // _FILTER_H_
