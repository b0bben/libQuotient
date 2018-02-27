/******************************************************************************
 * THIS FILE IS GENERATED - ANY EDITS WILL BE OVERWRITTEN
 */

#include "tags.h"

#include "converters.h"

#include <QtCore/QStringBuilder>

using namespace QMatrixClient;

static const auto basePath = QStringLiteral("/_matrix/client/r0");

class GetRoomTagsJob::Private
{
    public:
        QJsonObject tags;
};

QUrl GetRoomTagsJob::makeRequestUrl(QUrl baseUrl, const QString& userId, const QString& roomId)
{
    return BaseJob::makeRequestUrl(baseUrl,
            basePath % "/user/" % userId % "/rooms/" % roomId % "/tags");
}

GetRoomTagsJob::GetRoomTagsJob(const QString& userId, const QString& roomId)
    : BaseJob(HttpVerb::Get, "GetRoomTagsJob",
        basePath % "/user/" % userId % "/rooms/" % roomId % "/tags")
    , d(new Private)
{
}

GetRoomTagsJob::~GetRoomTagsJob() = default;

const QJsonObject& GetRoomTagsJob::tags() const
{
    return d->tags;
}

BaseJob::Status GetRoomTagsJob::parseJson(const QJsonDocument& data)
{
    auto json = data.object();
    d->tags = fromJson<QJsonObject>(json.value("tags"));
    return Success;
}

SetRoomTagJob::SetRoomTagJob(const QString& userId, const QString& roomId, const QString& tag, const QJsonObject& body)
    : BaseJob(HttpVerb::Put, "SetRoomTagJob",
        basePath % "/user/" % userId % "/rooms/" % roomId % "/tags/" % tag)
{
    setRequestData(Data(body));
}

QUrl DeleteRoomTagJob::makeRequestUrl(QUrl baseUrl, const QString& userId, const QString& roomId, const QString& tag)
{
    return BaseJob::makeRequestUrl(baseUrl,
            basePath % "/user/" % userId % "/rooms/" % roomId % "/tags/" % tag);
}

DeleteRoomTagJob::DeleteRoomTagJob(const QString& userId, const QString& roomId, const QString& tag)
    : BaseJob(HttpVerb::Delete, "DeleteRoomTagJob",
        basePath % "/user/" % userId % "/rooms/" % roomId % "/tags/" % tag)
{
}

