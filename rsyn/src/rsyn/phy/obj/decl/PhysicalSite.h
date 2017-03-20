/* Copyright 2014-2017 Rsyn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhysicalSite.h
 * Author: jucemar
 *
 * Created on 12 de Setembro de 2016, 22:47
 */

#ifndef PHYSICALDESIGN_PHYSICALSITE_H
#define PHYSICALDESIGN_PHYSICALSITE_H

namespace Rsyn {

class PhysicalSite : public Proxy<PhysicalSiteData> {
	friend class PhysicalDesign;
	friend class PhysicalDesignData;
protected:
	PhysicalSite(PhysicalSiteData * data) : Proxy(data) {}
public:
	PhysicalSite() : Proxy(nullptr) {}
	PhysicalSite(std::nullptr_t) : Proxy(nullptr) {}
	
	std::string getName() const;
	Rsyn::PhysicalSiteClass getClass() const;
	DBUxy getSize() const;
	DBU getWidth() const;
	DBU getHeight() const;
	DBU getLength(const Dimension dim) const;
}; // end class

} // end namespace 

#endif /* PHYSICALDESIGN_PHYSICALSITE_H */

