﻿#include "PropertySelectQueryProperty.h"

void PropertySelectQueryProperty::Serialize(RakNet::BitStream& stream) const
{
    stream.Write(CloneId);

	const auto& owner = GeneralUtils::ASCIIToUTF16(OwnerName);
	stream.Write(uint32_t(owner.size()));
	for (uint32_t i = 0; i < owner.size(); ++i) {
		stream.Write(static_cast<uint16_t>(owner[i]));
	}

	const auto& name = GeneralUtils::ASCIIToUTF16(Name);
	stream.Write(uint32_t(name.size()));
	for (uint32_t i = 0; i < name.size(); ++i) {
		stream.Write(static_cast<uint16_t>(name[i]));
	}

	const auto& description = GeneralUtils::ASCIIToUTF16(Description);
	stream.Write(uint32_t(description.size()));
	for (uint32_t i = 0; i < description.size(); ++i) {
		stream.Write(static_cast<uint16_t>(description[i]));
	}

    stream.Write(Reputation);
    stream.Write(IsBestFriend);
    stream.Write(IsFriend);
    stream.Write(IsModeratorApproved);
    stream.Write(IsAlt);
    stream.Write(IsOwner);
    stream.Write(AccessType);
    stream.Write(DatePublished);
    stream.Write(PerformanceCost);
}

void PropertySelectQueryProperty::Deserialize(RakNet::BitStream& stream) const
{
    // Do we need this?
}
