/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo (https://github.com/fizzyade/pingnoo)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 27/03/2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NEDRYSOFT_CORE_IRIBBONBARMANAGER_H
#define NEDRYSOFT_CORE_IRIBBONBARMANAGER_H

#include "ComponentSystem/IInterface.h"
#include "Core/IContextManager.h"
#include "CoreSpec.h"

namespace Nedrysoft::Core {
    class IRibbonPage;

    /**
     * @brief       The IRibbonBarManager interface describes an object that handles the creation of ribbon bars.
     *
     * @details     The IRibbonBarManager handles the management of the ribbon bar, it allows pages to be added
     *              to the ribbon.
     */
    class NEDRYSOFT_CORE_DLLSPEC IRibbonBarManager :
            public Nedrysoft::ComponentSystem::IInterface {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Returns the IRibbonBarManager instance.
             *
             * @return      the IRibbonBarManager singleton instance.
             */
            static IRibbonBarManager *getInstance() {
                return ComponentSystem::getObject<IRibbonBarManager>();
            }

            /**
             * @brief       Adds a page to the ribbon bar.
             *
             * @param[in]   title the title of the page.
             * @param[in]   id the identifier of the page.
             *
             * @returns     the IRibbonPage instance of the page.
             */
            virtual Nedrysoft::Core::IRibbonPage *addPage(QString title, QString id) = 0;

            /**
             * @brief       Returns the page given by the id.
             *
             * @param[in]   id the identifier of the page.
             *
             * @returns     if it exists, the IRibbonPage instance of the page; otherwise nullptr.
             */
            virtual Nedrysoft::Core::IRibbonPage *page(QString id) = 0;
    };
}

Q_DECLARE_INTERFACE(Nedrysoft::Core::IRibbonBarManager, "com.nedrysoft.core.IRibbonBarManager/1.0.0")

#endif // NEDRYSOFT_CORE_IRIBBONBARMANAGER_H
