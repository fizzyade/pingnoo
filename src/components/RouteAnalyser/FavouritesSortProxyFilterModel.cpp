/*
 * Copyright (C) 2021 Adrian Carpenter
 *
 * This file is part of Pingnoo (https://github.com/nedrysoft/pingnoo)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 12/03/2021.
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

#include "FavouritesSortProxyFilterModel.h"

bool Nedrysoft::RouteAnalyser::FavouritesSortProxyFilterModel::filterAcceptsRow(
        int sourceRow,
        const QModelIndex &sourceParent) const {

    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    if (m_filterText.isEmpty()) {
        return true;
    }

    auto map = sourceModel()->data(index, Qt::UserRole+1).toMap();

    auto stringParts = map["name"].toString().toLower().split("/");

    for (auto string : stringParts) {
        if (string.contains(m_filterText.toLower())) {
            return true;
        }
    }

    return false;
}

auto Nedrysoft::RouteAnalyser::FavouritesSortProxyFilterModel::setFilterText(QString text) -> void {
    m_filterText = text;

    invalidateFilter();
}